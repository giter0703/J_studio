using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using Image = UnityEngine.UI.Image;


public class HelpMgr : MonoBehaviour
{
    public GameObject BgObj, QuitObj;
    Sprite Bg;
    public Sprite[] helpSprite;
    GameObject NextObj;
    public Button NextBtn;
    Button QuitBtn;
    public int ImageIdx;
    int page;
    
    // Start is called before the first frame update
    void Start()
    {
        page = 0;
        QuitObj = GameObject.Find("Quit");
        Bg = BgObj.GetComponent<Image>().sprite;
        QuitBtn = QuitObj.GetComponent<Button>();
        NextBtn.onClick.AddListener(NextImage);
        QuitBtn.onClick.AddListener(Back);
    }

    void Update()
    {
        if(Input.GetKeyDown(KeyCode.RightArrow))    //GetKeyDown은 GetKey와 다르게 키를 한번만 누르면 반응하도록 함.
        {
           NextImage();
        }
    }
    private void NextImage()
    {
        AudioManager.instance.PlaySfx(AudioManager.Sfx.Click);
        page++;
        page %= ImageIdx;
        //Debug.Log("page : "+page);
        BgObj.GetComponent<Image>().sprite = helpSprite[page];
    }
    private void Back()
    {
        AudioManager.instance.PlaySfx(AudioManager.Sfx.Click);
        SceneManager.LoadScene("GameStart");
    }
}
