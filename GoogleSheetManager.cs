using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

[System.Serializable]
public class GoogleSheetManager : MonoBehaviour
{
    public GameObject GameStart;
    public Image diceImage;
    GameObject GameStartPrefab;
    
    const string URL = "https://script.google.com/macros/s/AKfycbwqQqRmBCdYG4KbCMWo64GjS1popUJCTgChH2vLvsaByiAFY2z-YMFGovV1JyF9ywaDAg/exec";
    public static List<GoogleSheetRow> sheetData = new List<GoogleSheetRow>();
    [System.Serializable]
    public class GoogleSheetRow
    {
        public int num;
        public string problem;
        public string answer;
        public string difficulty;
        public int point;
        public string commentary;
    }

    [System.Serializable]
    public class GoogleSheetResponse
    {
        public List<GoogleSheetRow> rows;
    }

    void Start() {
        StartCoroutine(LoadGoogleSheetData());
        GameStart.SetActive(true);
        GameStartPrefab = Instantiate(GameStart);
        diceImage.gameObject.SetActive(false);
    }
    // 구글 시트 데이터를 불러오는 코루틴
    IEnumerator LoadGoogleSheetData()
    {
        Debug.Log("코루틴 시작");
        using (UnityWebRequest www = UnityWebRequest.Get(URL))
        {
            yield return www.SendWebRequest();

            if (www.result == UnityWebRequest.Result.Success)
            {
                //데이터 가져오기
                string rawJson = www.downloadHandler.text;
                //Debug.Log("데이터 :\n" +rawJson);
                // 불필요한 접두사 제거
                string cleanJson = rawJson.Substring(rawJson.IndexOf("{"), rawJson.LastIndexOf("}") - rawJson.IndexOf("{") + 1);
                Debug.Log("cleanJson :\n" +rawJson);

                // JSON을 파싱하여 GoogleSheetResponse로 변환
                GoogleSheetResponse response = JsonUtility.FromJson<GoogleSheetResponse>(cleanJson);

                // 데이터 리스트를 업데이트
                sheetData = response.rows;
                Debug.Log(sheetData.Count);
                // for(int i = 0; i < sheetData.Count; i++){
                //     Debug.Log(sheetData[i].problem + " " + sheetData[i].num);
                // }
                if (GameStartPrefab != null)
                {
                    Destroy(GameStartPrefab);  // 프리팹을 파괴하여 화면에서 제거
                    diceImage.gameObject.SetActive(true);
                }
            }
            else
            {
                Debug.LogError("Failed to load data from Google Sheets: " + www.error);
            }

        }
    }

    // IEnumerator Start()
    // {
    //     UnityWebRequest www = UnityWebRequest.Get(URL);
    //     yield return www.SendWebRequest();

    //     string data = www.downloadHandler.text;
    //     print(data);
    // }
}
