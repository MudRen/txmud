// Room: /wiz/zling/txmap1.c

inherit ROOM;
void create()
{
    set("short","老狼居");//
    set("long",@LONG
                      欢迎来到土狼窝!
这里是土狼的家。墙上挂着一张他的照片,笑的憨憨的。房子里
什么也没有。

                   墙上挂的是《天下》的交通图
长安城-cac     奉天城-ftc     左家村-zjc     明月岛-myd 
无名岛-wmd     绯雨阁-fyg     排云寨-pyz     大同府-dtf 
黑风寨-hfz     天水镇-tsz     华山派-hsp     华阴村-hyc 
紫霞宫-zxg     汶川镇-wcz     少林寺-sls     开封府-kff
马封山-mfs     康安寨-kaz     牛头山-nts     杭州城-hzc
成都  -cd      唐门  -tm 

LONG
          );//
set("exits", ([ //
                "cac"  : "/d/changan/jiulou3",
                "ftc"  : "/d/fengtian/jiulou",
                "zjc"  : "/d/jinghai/zhuque6",
                "myd"  : "/d/jinghai/moon7",
                "wmd"  : "/d/jinghai/wm3",
                "fyg"  : "/d/feiyu/yu21",
                "pyz"  : "/d/paiyun/lh_tang",
                "dtf"  : "/d/datong/minju3",
                "hfz"  : "/d/heifeng/maowu",
                "tsz"  : "/d/tianshui/cross",

                "hsp"  : "/d/huashan_zx/guange3",
                "hyc"  : "/d/huayin/daguchang",
                "zxg"  : "/d/huashan_zx/yingbi",
                "wcz"  : "/d/wenchuan/fulai",
                "sls"  : "/d/shaolin/f_square",
                "kff"  : "/d/kaifeng/kai74",
                "mfs"  : "/d/mafeng/fengd9",
                "kaz"  : "/d/changan/jiulou3",
                "nts"  : "/d/changan/jiulou3",
                "hzc"  : "/d/hangzhou/hotel",

                "cd"  : "/d/chengdu/furuilou",
                 "tm"  : "/d/tangmen/fyuan",
        ]));//

    set("no_clean_up",0);//
    set("sleep_room",1);
    setup();
replace_program(ROOM);//
}
