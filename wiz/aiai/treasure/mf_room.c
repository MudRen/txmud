// mf_room.c
#include <ansi.h>
inherit ROOM;

#ifndef F_TREASURE
//#define F_TREASURE            __DIR__"obj/treasure"
#define F_TREASURE              __DIR__"treasure"
#endif

int magic_find(string str);

void create()
{    
     set("short", "ħ��ɮԺ");    
     set("long", "��������С����ͷ�����ħ��ʦ��ͬ����ħ�������о��ĵط���ɮԺ
�ڵ�ħ�������洦�ɼ����������Ҫ�Ļ������Լ�(mf)�ɡ�\n");
    set("exits", ([ /* sizeof() == 1 */
    //"north" : "/open/common/room/inn",            
     "north" :"/wiz/aiai/workroom",
]));             set("light_up",1);        
     set("objects", ([                //__DIR__"npc/mfer": 3 ]) );
     __DIR__"mfer": 3 ]));        
     setup();        
} 

void init()
{
        add_action("magic_find", "find");
        add_action("magic_find", "mf");
}

int magic_find(string str)
{
   if (!F_TREASURE->tr_make(environment(this_player())))
 message_vision("$N����magic find��һ�£�����ʲôҲû�з��֡�\n", 
      this_player());

  new(__DIR__"mfer")->move(environment(this_player()));
 message_vision("$N����һ�������ˣ����������\n", 
           this_player());

        return 1;
}

