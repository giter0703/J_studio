using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using Unity.VisualScripting;


public class Chance : MonoBehaviour
{
    GameControl gc;
    ProblemsControl pc;

    
    public GameObject Card;

    private Button CardBtn;

    public GameObject ChanceBoard;
    
    public GameObject Quit;
    Button QuitBtn;
    public Text CardTitle;

    //public static int chaneWayPoint1;
    //public static int chaneWayPoint2;

    
    int cardRd1;
    int rd1;

    // Start is called before the first frame update
    void Start()
    {
        for(int i = 0; i < 3; i++)  CardBtn = Card.GetComponentInChildren<Button>();
        QuitBtn = Quit.GetComponentInChildren<Button>();
        Card.SetActive(true);
        AudioManager.instance.PlaySfx(AudioManager.Sfx.Swish);
        CardBtn.onClick.AddListener(Clear);
        QuitBtn.onClick.AddListener(Back);
        ChanceBoard.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void Back()
    {
        Destroy(ProblemsControl.chancePrefab);
        ProblemsControl.diceImage.SetActive(true);
        ProblemsControl._doChance = true;
        GameControl.SwitchTurn();
        AudioManager.instance.PlaySfx(AudioManager.Sfx.Click);
    }

    private void Clear()
    {
        ProblemsControl.diceImage.SetActive(false);
        AudioManager.instance.PlaySfx(AudioManager.Sfx.Pouting);
        int k = Random.Range(0, 3);
        switch(k){
            case 0:
                StealPoint();
                break;
            case 1:
                AddPoint();
                break;
            case 2:
                MinusPoint();
                break;
        }
        Card.SetActive(false);
        ChanceBoard.SetActive(true);
    }
    
    private int CardRandom1()
    {
        cardRd1 = Random.Range(0, 3);
        Debug.Log("rd : " + cardRd1);
        return cardRd1;
    }

    private int Random1()
    {
        rd1 = Random.Range(1, 4);
        Debug.Log("rd : " + rd1);
        return rd1;
    }
    
    //상대방 점수 1~3점 뺏기
    public void StealPoint()
    {
        int sp = Random1(); 
        if(DiceRoller.whosTurn == -1)
        {
            Debug.Log(PlayerPrefs.GetString("RedNick")+"팀이 "+PlayerPrefs.GetString("BlueNick")+"팀의 점수를 "+sp+"만큼 뺏기");
            CardTitle.text = PlayerPrefs.GetString("RedNick")+"팀이 "+PlayerPrefs.GetString("BlueNick")+"팀의 점수를 "+sp+"만큼 뺏기";
            GameControl.player1Score += sp;
            GameControl.player2Score -= sp;
        }
        else if(DiceRoller.whosTurn == 1)
        {
            Debug.Log(PlayerPrefs.GetString("BlueNick")+"팀이 "+PlayerPrefs.GetString("RedNick")+"팀의 점수를 "+sp+"만큼 뺏기");
            CardTitle.text = PlayerPrefs.GetString("BlueNick")+"팀이 "+PlayerPrefs.GetString("RedNick")+"팀의 점수를 "+sp+"만큼 뺏기";
            GameControl.player2Score += sp;
            GameControl.player1Score -= sp; 
        }
    }

    //본인 점수 1~3점 추가
    public void AddPoint()
    {
        int ap = Random1();
        if(DiceRoller.whosTurn == -1)
        {
            Debug.Log(PlayerPrefs.GetString("RedNick")+"팀, "+ap+"만큼 점수 추가");
            CardTitle.text = PlayerPrefs.GetString("RedNick")+"팀, "+ap+"만큼 점수 추가";
            GameControl.player1Score += ap;
        }
        else if(DiceRoller.whosTurn == 1)
        {
            Debug.Log(PlayerPrefs.GetString("BlueNick")+"팀, "+ap+"만큼 점수 추가");
            CardTitle.text = PlayerPrefs.GetString("BlueNick")+"팀, "+ap+"만큼 점수 추가";
            GameControl.player2Score += ap;
        }
    }

    //본인 점수 1~3점 잃음
    public void MinusPoint()
    {
        int mp = Random1();
        if(DiceRoller.whosTurn == -1)
        {
            Debug.Log(PlayerPrefs.GetString("RedNick")+"팀, "+mp+"만큼 점수 감점");
            CardTitle.text = PlayerPrefs.GetString("RedNick")+"팀, "+mp+"만큼 점수 감점";
            GameControl.player1Score -= mp;
        }
        else if(DiceRoller.whosTurn == 1)
        {
            Debug.Log(PlayerPrefs.GetString("BlueNick")+"팀, "+mp+"만큼 점수 감점");
            CardTitle.text = PlayerPrefs.GetString("BlueNick")+"팀, "+mp+"만큼 점수 감점";
            GameControl.player2Score -= mp;
        }
    }
}
