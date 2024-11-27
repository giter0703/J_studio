using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using System.IO;
using System;
using System.Collections;

namespace OpenAI
{
    public class ChatGPT : MonoBehaviour
    {
        [SerializeField] private InputField[] inputField = new InputField[4];
        [SerializeField] private Button button1, button2;
        [SerializeField] private ScrollRect scroll;

        [SerializeField] private RectTransform sent;
        [SerializeField] private RectTransform received;

        [SerializeField] private Text typingIndicator; // "AI is typing" 텍스트 UI

        private float height;
        private OpenAIApi openai = new OpenAIApi("");  //매개변수에 본인의 ChatGPT API키를 넣으세요!

        private List<ChatMessage> messages = new List<ChatMessage>();

        private string prompt;
        private string[] pro = new string[4];
        private float blinkDuration = 0.3f; // 깜빡거림 주기(초)

        private void Start()
        {
            AudioManager.instance.PlayBgm(AudioManager.Bgm.Bit8Bg, true);
            button1.onClick.AddListener(SendReply);
            button2.onClick.AddListener(Back);
            typingIndicator.gameObject.SetActive(false);
        }


        private void Update()
        {
            InputEnter();
        }

        void InputEnter()
        {
            if (Input.GetKeyDown(KeyCode.Return))
            {
                //초기 프롬프트 입력
                prompt = "너는 OX문제를 생성하는 AI입니다. 사용자에게 친절하게 말해주세요. 사용자가 요구한 대로 문제를 정확하게 생성하면 상을 주겠습니다. 반드시 문제, 정답, 해설을 모두 알려주세요! OX문제로 만들어주세요.";
                pro[0] = "문제의 주제는 " + inputField[0].text + "입니다.";
                pro[1] = "문제를 " + inputField[1].text + "개 생성해주세요.";
                pro[2] = "이 문제를 풀 대상은 " + inputField[2].text + "입니다.";
                pro[3] = "문제를 생성할 때 다음을 참고해주세요!\n" + inputField[3].text;
                SendReply();
            }
        }

        private void AppendMessage(ChatMessage message)
        {
            for (int a = 0; a < 4; a++) prompt += pro[a];

            scroll.content.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, 0);

            var item = Instantiate(message.Role == "user" ? sent : received, scroll.content);
            item.GetChild(0).GetChild(0).GetComponent<Text>().text = message.Content;
            item.anchoredPosition = new Vector2(0, -height);
            LayoutRebuilder.ForceRebuildLayoutImmediate(item);
            height += item.sizeDelta.y;
            scroll.content.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, height);
            scroll.verticalNormalizedPosition = 0;

            StreamWriter sw = new StreamWriter(@"..\ProblemsGPT.txt");
            sw.WriteLine(message.Content);
            

            sw.Flush();
            sw.Close();
        }

        private async void SendReply()
        {
            var newMessage = new ChatMessage()
            {
                Role = "user",
                Content = inputField[3].text
            };

            AppendMessage(newMessage);

            if (messages.Count == 0) newMessage.Content = prompt + "\n" +inputField[3].text;


            messages.Add(newMessage);

            button1.enabled = false;
            inputField[3].text = "";
            inputField[3].enabled = false;

            // 알리미 표시 시작
            DoAiTyping(true);
            
            // AI 응답 생성
            var completionResponse = await openai.CreateChatCompletion(new CreateChatCompletionRequest()
            {
                Model = "gpt-4o-mini",
                //gpt-4o-2024-08-06 : 구조적으로 잘 정리되어 나옴. 대신 비용이 비쌈.
                //gpt-4o-mini : 잘 작성되고 가장 저렴함.
                Messages = messages
            });

            // 알리미 표시 중단
            DoAiTyping(false);

            if (completionResponse.Choices != null && completionResponse.Choices.Count > 0)
            {
                var message = completionResponse.Choices[0].Message;
                message.Content = message.Content.Trim();

                messages.Add(message);

                Debug.Log(message);
                
                AppendMessage(message);
            }
            else
            {
                Debug.LogWarning("No text was generated from this prompt.");
            }

            button1.enabled = true;
            inputField[3].enabled = true;
        }

        private void Back()
        {
            prompt = "";
            AudioManager.instance.PlayBgm(AudioManager.Bgm.Bit8Bg, false);
            AudioManager.instance.PlaySfx(AudioManager.Sfx.Click);
            SceneManager.LoadScene("GameStart");
        }
        private void DoAiTyping(bool d){
            typingIndicator.gameObject.SetActive(d);
            StartCoroutine("BlinkText");
        }
        IEnumerator BlinkText()
        {
            while (true) // 무한 반복
            {
                Text textToBlink = typingIndicator;
                // Alpha 값을 0으로 설정해 텍스트를 투명하게 만듦
                textToBlink.color = new Color(textToBlink.color.r, textToBlink.color.g, textToBlink.color.b, 0f);
                // 깜빡임 주기 대기
                yield return new WaitForSeconds(blinkDuration);

                // Alpha 값을 1로 설정해 텍스트를 보이게 만듦
                textToBlink.color = new Color(textToBlink.color.r, textToBlink.color.g, textToBlink.color.b, 1f);
                // 깜빡임 주기 대기
                yield return new WaitForSeconds(blinkDuration);
            }
        }
    }
}
