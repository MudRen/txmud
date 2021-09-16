// workroom.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"小山茅舍"NOR);
        set("long",@long
这里是无聊说者的隐居之地。屋子不大，但是很整洁。屋里
最显眼的是一幅中堂画，上面只有四个字：心怀天下。角落里摆
着一张床，窗前是一个小书桌，上面零乱的放着些东西，似乎是
无聊说者还没完成的作品。墙上还贴着一幅地图(map)，因为有
窗户(window)里透来的光，你可以毫不费力的看清楚上面写的东
西。
\t天下关闭，好是痛心，却向何处，寻觅旧人。。
long
        );

        set("no_clean_up", 1);
        set("sleep_room",1);
       set("exits",([
        "lz":__DIR__"work/linzhi/lz_cross",
        "out":"/d/shaolin/fayanvoid",
        "up": __DIR__"home/sleeproom",
        "cac" : "/d/changan/jiulou",
        "cd" : "/d/chengdu/furuilou",
        "dtf" : "/d/datong/ylinn",
        "kff" : "/d/kaifeng/kai79",
        "hzc" : "/d/hangzhou/hotel",
        "ftc" : "/d/fengtian/jiulou",
        ]));

     set("objects",([
        "/obj/furniture/chuang" : 1,
        "/obj/furniture/shuzhuo" : 1,
        ]));                                            
       set("item_desc",([
        "window" : "窗外种着几株梅花，似乎有香气透窗而入。\n",
                "map" : 
HIW "                          天 下 地 图

    长安城-cac     奉天城-ftc     左家村-zjc     明月岛-myd 
    无名岛-wmd     绯雨阁-fyg     排云寨-pyz     大同府-dtf 
    黑风寨-hfz     天水镇-tsz     华山派-hsp     华阴村-hyc 
    紫霞宫-zxg     汶川镇-wcz     少林寺-sls     开封府-kff
    马封山-mfs     康安寨-kaz     牛头山-nts     杭州城-hzc
    成都  -cd      唐门  -tm      雪亭镇-xtz     踏雪庄-txz

    输入qu cac就可以去到长安城，其余的地方也可以类似地到达。
" NOR,

]));

        set("valid_startroom", 1);
        setup(); 
}

void init()
{
        add_action("do_save","save");
        add_action("do_qu","qu");
}
 
int do_save(string arg)
{
        object me = this_player();

        if(me && geteuid(me) == "saying")
                return 0;
        else
        {
                tell_object(me, "这里是无聊说者的家，你不能设定这里为起始地点。\n");
                return 1;
        }
}
int do_qu(string arg)                                   
{
         object me;
                me = this_player();
        if (!arg)
         return notify_fail("添加目标地点才能到达。\n");

        if ( arg =="cac")
        {
                me->move("/d/changan/jiulou");
                return 1;
        }
 
        if ( arg =="ftc")
        {
                me->move("/d/fengtian/cross");
                return 1;       
         }

        if ( arg =="zjc")
        {
                me->move("/d/zuojiacun/lu18");
                return 1;                               
        }

        if ( arg =="myd")
        {
                me->move("/d/jinghai/moon7");
                return 1;       
        }

        if ( arg =="wmd")
        {
                me->move("/d/jinghai/wm9");
                return 1;       
        }

        if ( arg =="fyg")
        {
                me->move("/d/feiyu/yu21");
                return 1; 
        }

        if ( arg =="pyz")
        {
                me->move("/d/paiyun/door");
                return 1;
        }

        if ( arg =="dtf")
        {
                me->move("/d/datong/shizilukou");
                return 1; 
        }

        if ( arg =="hfz")
        {
                me->move("/d/heifeng/cross");
                return 1; 
        }

        if ( arg =="tsz")
        {
                me->move("/d/tianshui/cross");
                return 1;
        }

        if ( arg =="hsp")
        {
                me->move("/d/huashan_zx/yingbi");       
                return 1;
        }

        if ( arg =="hyc")
        {
                me->move("/d/huayin/xiaolu1");
                return 1;
        }

        if ( arg =="zxg")
        {
                me->move("/d/huashan_zx/yingbi");
                return 1;
        }

        if ( arg =="wcz")
        {
                me->move("/d/wenchuan/zhenkou");
                return 1;
        }

        if ( arg =="sls")                               
        {
                me->move("/d/shaolin/f_square");
                return 1;
        }

        if ( arg =="kff")
        {
                me->move("/d/kaifeng/kai74");
                return 1;
        }       

        if ( arg =="mfs")
        {
                me->move("/d/mafeng/fengd9");
                return 1;
        }

        if ( arg =="kaz")
        {
                me->move("/d/path3/k_s9");
                return 1;
        }

        if ( arg =="nts")                               
        {
                me->move("/d/path3/k_h15");
                return 1;
        }

        if ( arg =="hzc")
        {
                me->move("/d/hangzhou/cross");
                return 1;
        }

        if ( arg =="cd")
        {
                me->move("/d/chengdu/shizi1");
                return 1;
        }

        if ( arg =="tm")
        {
                me->move("/d/tangmen/fyuan");
                return 1;
        }

        if ( arg =="xtz")                               
        {
                me->move("/d/xueting/guangchang");
                return 1;
        }

        if ( arg =="txz")
        {
                me->move("/d/taxue/dating");
                return 1;
        }
        else return notify_fail("你要去的地方不在地图之上。\n");
}
