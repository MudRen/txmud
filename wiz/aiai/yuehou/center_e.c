// /d/yuehou/center_e.c

inherit ROOM;

void create()
{
        set("short", "�㳡����");
        set("long", @LONG
������������Ĺ㳡�Ķ��࣬�����в���ס�ң�������һ��
��ջ��
LONG
        );

       set("exits", ([
                "south"             : __DIR__"kezhan",
                "west"             : __DIR__"tcenter",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

