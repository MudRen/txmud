// houhuayuan.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","��ɽ");
	set ("long",@long
����һ����԰�Աߵļ�ɽ����ɽ�Ա�������ɽ�軨����ʯ������ɽ�軨
�У�����ν: ��ǧ����ʼ����, �̱����ð����桱�������ġ� ̧ͷ��ȥ, 
ֻ��һ�����٣�teng�������ڻ�԰ǽ�ϡ�һ����Ȫ�Ӽ�ɽ��ӿ������һ����
����Ƣ��
long);
         set("resource/water", 1);

         set("exits",([

             "northeast" : __DIR__"huayuan",
	]));

        set("objects", ([
                __DIR__"npc/dizi7" : 1,
        ]));

         set("item_desc",([
             "teng" : "һ��˳��ǽ�����Ӷ��ϵ������١�\n"
	]));
	setup();
}
/*
int init()
{
	add_action("do_pa","pa");
}
                
int do_pa(string arg)
{
         object me;
         me = this_player();
         if (arg != "teng")
         return notify_fail("��Ҫ��ʲô��\n");
         if ( arg =="teng")
         { 
         write("�����Ŵ�����������ȥ��\n");
         message("vision",
         me->name() + "���Ŵ�����������ȥ��\n",
                     environment(me), ({me}) );
         me->move(__DIR__"shuteng");
         message("vision",
                  me->name() + "��������������������\n",
                             environment(me), ({me}) );
                }
                return 1;
}
*/     