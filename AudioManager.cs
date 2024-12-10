using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AudioManager : MonoBehaviour
{
    // 모든 곳에서 사용할 수 있도록 함.
    public static AudioManager instance;

    // 배경음악
    [Header("BGM")]
    public AudioClip[] bgmClips;
    public float bgmVolume = 0.3f;
    private AudioSource[] bgmPlayer;
    public int bgmChannels = 0;
    private int bgmChannelIndex;

    // 효과음
    [Header("SFX")]
    public AudioClip[] sfxClips;
    public float sfxVolume = 1.0f;
    public int channels = 10;
    private AudioSource[] sfxPlayer;
    private int channelIndex = 0;

    public enum Sfx { Click=0, Congrats, Correct, Katalk, Save, Typing, Wrong=6, Swish, Pop, Pouting }  //열거형
    public enum Bgm {GameStartBg=0, Bit8Bg, FunnyBg}    //열거형

    void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        Init();
    }

    void Init()
    {
        // 배경음악 초기화
        bgmPlayer = new AudioSource[bgmChannels];
        for (int i = 0; i < bgmChannels; i++)
        {
            GameObject bgmObj = new GameObject($"BgmPlayer_{i}");
            bgmObj.transform.parent = transform;
            bgmPlayer[i] = bgmObj.AddComponent<AudioSource>();
            bgmPlayer[i].playOnAwake = false;
            bgmPlayer[i].loop = true;
            bgmPlayer[i].volume = bgmVolume;
            bgmPlayer[i].clip = bgmClips[i];
        }
        //bgmObj.transform.parent = transform;
        // bgmPlayer = bgmObj.AddComponent<AudioSource>();
        // bgmPlayer.playOnAwake = false;
        // bgmPlayer.loop = true;
        // bgmPlayer.volume = bgmVolume;
        // bgmPlayer.clip = bgmClip;

        // 효과음 초기화
        sfxPlayer = new AudioSource[channels];
        for (int i = 0; i < channels; i++)
        {
            GameObject sfxObj = new GameObject($"SfxPlayer_{i}");
            sfxObj.transform.parent = transform;
            sfxPlayer[i] = sfxObj.AddComponent<AudioSource>();
            sfxPlayer[i].playOnAwake = false;
            sfxPlayer[i].volume = sfxVolume;
            sfxPlayer[i].clip = sfxClips[i];
        }
    }

    // public void PlayBgm(bool isPlay)
    // {
    //     if (isPlay)
    //     {
    //         if (!bgmPlayer.isPlaying) bgmPlayer.Play();
    //     }
    //     else
    //     {
    //         bgmPlayer.Stop();
    //     }
    // }
    public void PlayBgm(Bgm bgm, bool isPlay)
    {
        for (int a = 0; a < bgmPlayer.Length; a++)
        {
            if(isPlay && (!bgmPlayer[a].isPlaying))
            {
                if((bgmPlayer[a].clip == bgmClips[(int)bgm]))
                {
                    bgmPlayer[a].Play();
                }
                else{
                    bgmPlayer[a].Stop();
                }
            }
            else{
                bgmPlayer[a].Stop();
            }
        }
    }

    public void PlaySfx(Sfx sfx)
    {
        // 효과음을 재생할 수 있는 채널 찾기
        for (int i = 0; i < sfxPlayer.Length; i++)
        {
            int loopIndex = (i + channelIndex) % sfxPlayer.Length;

            if (!sfxPlayer[loopIndex].isPlaying)
            {
                channelIndex = (loopIndex + 1) % sfxPlayer.Length; // 다음 채널로 갱신
                sfxPlayer[loopIndex].clip = sfxClips[(int)sfx];
                sfxPlayer[loopIndex].Play();
                return;
            }
        }

        // 모든 채널이 재생 중일 경우 첫 번째 채널에서 강제 재생
        sfxPlayer[channelIndex].Stop();
        sfxPlayer[channelIndex].clip = sfxClips[(int)sfx];
        sfxPlayer[channelIndex].Play();
        channelIndex = (channelIndex + 1) % sfxPlayer.Length; // 다음 채널로 갱신
    }
}
