// Room: /wiz/qifan/workroom.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG "踏雪山庄" NOR);
        set("long",
"这里是踏雪无痕的住所，平时这里总是悄无声息，但窗户上不\n"
"时映出踏雪无痕低头沉思的身影。迎面的墙上挂着一幅对联(lian)，\n"
"右面墙上挂着一张地图(ditu)。屋子最上方写着两行字：\n\n"
            HIR "\t任何人在任何情况下不能随意更改玩家数据\n"
            HIR"\t任何人在任何情况下违反天条都将受到惩罚\n\n"NOR
);

        set("exits",([
	"out" : "/d/death/gate",
	]));

        set("objects", ([
                __DIR__"user" : 1,
        ]));

	set("item_desc", ([

	"ditu" : 
WHT "\n    长安城-cac     奉天城-ftc     左家村-zjc     明月岛-myd 
    无名岛-wmd     绯雨阁-fyg     排云寨-pyz     大同府-dtf 
    黑风寨-hfz     天水镇-tsz     华山派-hsp     华阴村-hyc 
    紫霞宫-zxg     汶川镇-wcz     少林寺-sls     开封府-kff
    马封山-mfs     康安寨-kaz     牛头山-nts     杭州城-hzc
    成都  -cd      唐门  -tm      雪亭镇-xtz     踏雪庄-txz

    如果您想去什么地方,请输入qu xxx 就可以到达你想到达的地方!\n" NOR,
        "lian" : HIC "\n书山有路勤为径 学海无涯苦作舟\n" NOR,

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
        object me = this_player(1);

        if(me && geteuid(me) == "qifan")
                return 0;
        else
                return 1;
}

int do_qu(string arg)
{
         object me;
         me = this_player();
         if( !arg )
         return notify_fail("您想去什么地方？\n");

        if ( arg =="cac")
         {
                me->move("/d/changan/jiulou2");
                return 1;
         }
         
        if ( arg =="ftc")
         {
                me->move("/d/fengtian/jiulou");
                return 1;       
         }
        
        if ( arg =="zjc")
         {
                me->move("/d/jinghai/zhuque6");
                return 1; 
        }

        if ( arg =="myd")
         {
                me->move("/d/jinghai/moon7");
                return 1;       
        }

        if ( arg =="wmd")
         {
                me->move("/d/jinghai/wm3");
                return 1;       
        }


        if ( arg =="fyg")
         {
                me->move("/d/feiyu/yu21");
                return 1; 
        }

        if ( arg =="pyz")
         {
                me->move("/d/paiyun/lh_tang");
                return 1; 
        }

        if ( arg =="dtf")
         {
                me->move("/d/datong/minju3");
                return 1; 
        }

        if ( arg =="hfz")
         {
                me->move("/d/heifeng/maowu");
                return 1; 
        }
 
        if ( arg =="tsz")
         {
                me->move("/d/tianshui/cross");
                return 1;
        }

        if ( arg =="hsp")
         {
                me->move("/d/huashan_zx/guange3");
                return 1;
        }

        if ( arg =="hyc")
         {
                me->move("/d/huayin/daguchang");
                return 1;
        }

        if ( arg =="zxg")
         {
                me->move("/d/huashan_zx/yingbi");
                 return 1;
        }

        if ( arg =="wcz")
         {
                me->move("/d/wenchuan/fulai");
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
                me->move("/d/changan/jiulou3");
                 return 1;
        }

        if ( arg =="nts")
         {
                me->move("/d/changan/jiulou3");
                 return 1;
        }
        
        if ( arg =="hzc")
         {
                me->move("/d/hangzhou/hotel");
                 return 1;
        }

        if ( arg =="cd")
         {
                me->move("/d/chengdu/furuilou");
                 return 1;
        }

        if ( arg =="tm")
         {
                me->move("/d/tangmen/fyuan");
                 return 1;
        }

        if ( arg =="xtz")
         {
                me->move("/d/changan/jiulou2");
                 return 1;
        }

        if ( arg =="txz")
         {
                me->move("/d/changan/jiulou2/");
                 return 1;
        }
		return 0;
}