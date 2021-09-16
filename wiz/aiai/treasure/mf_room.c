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
     set("short", "魔法僧院");    
     set("long", "这里是由小艾带头，许多魔术师共同从事魔法宝物研究的地方，僧院
内的魔法宝物随处可见，你如果想要的话，就自己(mf)吧。\n");
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
 message_vision("$N到处magic find了一下，但是什么也没有发现。\n", 
      this_player());

  new(__DIR__"mfer")->move(environment(this_player()));
 message_vision("$N做了一个宝物人，放在了这里。\n", 
           this_player());

        return 1;
}

