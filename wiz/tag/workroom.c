// workroom.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "不好的工作室");
        set("long",
"这里就是不好的工作室。在学习之余，不好会来到这个工作\n"
"室，坐在书桌前构思与写作。书桌上摆着一份《工作室说明》，\n"
"墙上贴着一张天下的地图和一条标语：“"+ HIY"追 求 真 理"NOR +"。”\n"
        );

        set("no_clean_up", 1);

        set("exits",([
        "kaz" : __DIR__"d/kanganzhai/gate",
        "snake" : __DIR__"d/path1/tch_ft17",
        "dt" : __DIR__"d/gaibang/dt_fenduo",
        "ca" : __DIR__"d/gaibang/ca_fenduo",
        "out" : "/d/changan/jiulou",
        "up" : __DIR__"upstairs",
        "ft" : __DIR__"d/gaibang/ft_fenduo",
        "kf" : __DIR__"d/gaibang/kf_fenduo",
        ]));

        set("objects", ([
        __DIR__"home/desk" : 1,
        ]));

        set("item_desc", ([
        "instruction" : 
HIY "                         工 作 室 说 明

" NOR,
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

        if(me && geteuid(me) == "tag")
                return 0;
        else
        {
                tell_object(me, "这里是不好的工作室，你不能设定这里为启始地点。\n");
                return 1;
        }
}

int do_qu(string arg)
{
         object me;
         me = this_player();
         if( !arg )
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
                return notify_fail("这里路径没有设定。\n");
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
