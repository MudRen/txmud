// workroom.c

#include <ansi.h>

inherit ROOM;

void create ()
{
    set ("short", "老土狼的小窝");
    set("long", "常回家看看，回家看看。\n");
    set("objects",([
        __DIR__"npc/test" : 1,
    ]));

  set("exits", ([ /* sizeof() == 1 */
   "down" : __DIR__"txmap",
]));

  setup();
}

void init()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];       
        add_action("do_look", "look");
}

/*
30-260        午夜
260-510       黎明
510-630       早晨
630-810       中午
810-990       傍晚
990-1170      下午
1170-1360     傍晚
1360-第二天30 夜晚
*/

int do_look()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];
      
        if( t > 30 && t < 510)
        {
                set("long", HIY"还有人没有睡觉？老土狼可开始做梦了。你如果这时看到这里，肯定看不见他\n"NOR);
        }
        if( t > 510 && t < 630)
        {
                set("long", HIY"现在已经上班了，应该可以看到老土狼了，有空大家都过来坐坐。\n"NOR);
        }
        if( t < 810 && t > 630)
        {
                set("long", HIW"吃午饭了，还有人没有吃吗？去吃吧。\n"NOR);
        }
        if( t < 990 && t > 810)
        {
                set("long", HIG"晚餐是老土狼最寂寞的时候，自己一个人宁肯不吃饭。惨......\n"NOR);
        }
        if( t < 1360 && t > 990)
        {
                set("long", HIR"没有网络,只能cs,vb delphi sql 枯燥中......\n"NOR);
        }
        if( t < 30 || t > 1360)
        {
                set("long", BLU"夜深人静了，看看报纸该睡觉了。\n"NOR);
        }
}
int valid_leave(object me,string dir)
{
        if(!me)
                return 0;

if(dir == "down" || dir == "d")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_jinghai_book() :))))
                        return notify_fail("管事伸手拦住你说道：“奉寨主之命，本派典籍不可携出书房。”\n");
        }

        return ::valid_leave(me,dir);
}

