// xiaowu.c 小屋 

inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
十分简陋的一间小屋，屋里几乎什么也没有，只有一张桌子
和一张床,但是墙上却挂着一把十分锋利的斧子(axe)，你似乎忽
然想起了什么!
LONG
        );
       set("exits", ([
                "west"              : __DIR__"kongdi",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
