// Room: /wiz/zling/txmap1.c

inherit ROOM;
void create()
{
    set("short","���Ǿ�");//
    set("long",@LONG
                      ��ӭ����������!
���������ǵļҡ�ǽ�Ϲ���һ��������Ƭ,Ц�ĺ����ġ�������
ʲôҲû�С�

                   ǽ�Ϲҵ��ǡ����¡��Ľ�ͨͼ
������-cac     �����-ftc     ��Ҵ�-zjc     ���µ�-myd 
������-wmd     ����-fyg     ����կ-pyz     ��ͬ��-dtf 
�ڷ�կ-hfz     ��ˮ��-tsz     ��ɽ��-hsp     ������-hyc 
��ϼ��-zxg     �봨��-wcz     ������-sls     ���⸮-kff
���ɽ-mfs     ����կ-kaz     ţͷɽ-nts     ���ݳ�-hzc
�ɶ�  -cd      ����  -tm 

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
