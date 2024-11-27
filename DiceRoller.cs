using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DiceRoller : MonoBehaviour
{
    public static int diceResult;
    public Image diceImage;
    public Sprite[] diceSprites;
    //public Image diceSprite3D;
    public static int whosTurn = 1;
    private bool coroutineAllowed = true;
    Button button;

    [SerializeField] GameMgr _gameMgr;

    public Text diceText;
    private float blinkDuration = 0.3f;

    void Start()
    {
        StartCoroutine(BlinkDiceText());
        button = diceImage.GetComponentInChildren<Button>();
        button.onClick.AddListener(OnMouseDown);
    }
    public void OnMouseDown()
    {
        if(coroutineAllowed && !GameControl.gameOver)
        {
            AudioManager.instance.PlaySfx(AudioManager.Sfx.Click);
            StartCoroutine(RollDice());
        }
    }

    private IEnumerator RollDice()
    {
        coroutineAllowed = false;
        int i;
        for (i = 0; i <= 20; i++)
        {
            diceResult = Random.Range(0, 6);//주사위 값 0~5
            
            //주사위 이미지 호출
            if(diceResult == 0)
                diceImage.sprite = diceSprites[0];  //주사위1
            else if (diceResult == 1)
                diceImage.sprite = diceSprites[1];  //주사위2
            else if (diceResult == 2)
                diceImage.sprite = diceSprites[2];  //주사위3
            else if (diceResult == 3)
                diceImage.sprite = diceSprites[3];  //주사위4
            else if (diceResult == 4)
                diceImage.sprite = diceSprites[4];  //주사위5
            else if (diceResult == 5)
                diceImage.sprite = diceSprites[5];  //주사위6
            
            yield return new WaitForSeconds(0.06f);//이미지 몇 초 보여주기
        }
        yield return new WaitForSeconds(1.8f); //주사위를 굴리고 잠시 기다리기
        diceImage.sprite = diceSprites[6];  //초기 3차원 주사위 이미지
        GameControl.diceSideThrown = diceResult + 1;
        //StartCoroutine(BlinkDiceText());
        if(whosTurn == 1)
        {
            _gameMgr.SetCurPlayer(1);
            GameControl.MovePlayer(1);
        }
        else if(whosTurn == -1)
        {
            _gameMgr.SetCurPlayer(2);
            GameControl.MovePlayer(2);
        }
        whosTurn *= -1;
        coroutineAllowed = true;
        yield return new WaitForSeconds(2f);
    }
    public IEnumerator BlinkDiceText()
    {
        while (true) // 무한 반복
        {
            Text textToBlink = diceText;
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
