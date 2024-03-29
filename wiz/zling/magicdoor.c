// obj: /wiz/zling/fly.c

#include <ansi.h>
inherit ITEM;

void create()
{
       set_name(HIG "魔法门" NOR, ({"magic door","md"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                WHT "\n长安城-cac     奉天城-ftc     左家村-zjc     明月岛-myd 
无名岛-wmd     绯雨阁-fyg     排云寨-pyz     大同府-dtf 
黑风寨-hfz     天水镇-tsz     华山派-hsp     华阴村-hyc 
紫霞宫-zxg     汶川镇-wcz     少林寺-sls     开封府-kff
马封山-mfs     康安寨-kaz     牛头山-nts     杭州城-hzc
成都  -cd      唐门  -tm
如果您想去什么地方,请输入qu xxx 就可以到达你想到达的地方!
 \n");
                set("value", 5);
                     set("no_drop",1);
                set("unit", "扇");
        }
}


void init()
{
        add_action("do_qu","qu");
}


int do_qu(string arg)
{
         object me;
         me = this_player();
         if( !arg )
         return notify_fail("您想去什么地方？\n");

    if ( arg =="cac")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了长安。\n" NOR,me);
                me->move("/d/changan/jiulou2");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1;
         }
         
        if ( arg =="ftc")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了奉天。\n" NOR,me);
                me->move("/d/fengtian/jiulou");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1;       
         }
        
        if ( arg =="zjc")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了左家村。\n" NOR,me);
                me->move("/d/jinghai/zhuque6");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1; 

        }

        if ( arg =="myd")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了明月岛。\n" NOR,me);
                me->move("/d/jinghai/moon7");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1;       
        }

        if ( arg =="wmd")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了无名岛。\n" NOR,me);
                me->move("/d/jinghai/wm3");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1;       
        }

        if ( arg =="fyg")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了绯雨阁。\n" NOR,me);
                me->move("/d/feiyu/yu21");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1; 
        }

        if ( arg =="pyz")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了排云寨。\n" NOR,me);
                me->move("/d/paiyun/lh_tang");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1; 
        }

        if ( arg =="dtf")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了大同府。\n" NOR,me);
                me->move("/d/datong/minju3");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1; 
        }

        if ( arg =="hfz")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了黑风寨。\n" NOR,me);
                me->move("/d/heifeng/maowu");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                return 1; 
        }
 
        if ( arg =="tsz")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了天水镇。\n" NOR,me);
                me->move("/d/tianshui/cross");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="hsp")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了华山。\n" NOR,me);
                me->move("/d/huashan_zx/guange3");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="hyc")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了华阴村。\n" NOR,me);
                me->move("/d/huayin/daguchang");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="zxg")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了紫霞宫。\n" NOR,me);
                me->move("/d/huashan_zx/yingbi");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="wcz")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了汶川镇。\n" NOR,me);
                me->move("/d/wenchuan/fulai");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="sls")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了少林寺。\n" NOR,me);
                me->move("/d/shaolin/f_square");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="kff")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了开封。\n" NOR,me);
                me->move("/d/kaifeng/kai74");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }       

        if ( arg =="mfs")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了马封山。\n" NOR,me);
                me->move("/d/mafeng/fengd9");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="kaz")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了康安寨。\n" NOR,me);
                me->move("/d/changan/jiulou3");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="nts")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了牛头山。\n" NOR,me);
                me->move("/d/changan/jiulou3");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }
        
        if ( arg =="hzc")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了杭州。\n" NOR,me);
                me->move("/d/hangzhou/hotel");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="cd")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了成都。\n" NOR,me);
                me->move("/d/chengdu/furuilou");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }

        if ( arg =="tm")
         {
                message_vision(HIG "\n只见$N打开一扇魔法门，瞬间去了唐门。\n" NOR,me);
                me->move("/d/tangmen/fyuan");
                message_vision(HIG "\n地面突然暴出一道裂缝$N从里面钻了出来\n" NOR,me);
                 return 1;
        }
        return 0;
}

