// Room: /d/huashan/xiaolu2.c

inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
ɽ·Խ��Խ������ʱ��һЩ��Ҳ�в�������С�����·�ߵ�
�����дܳ�����Ҫ�����岻̫�ã����ǲ�Ҫ�������ˡ�·���ұ�
��һ��Сͤ�ӡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"xiaolu1",
  "east" : __DIR__"qiting",
  "northeast" : __DIR__"lin2",
  "northwest" : __DIR__"lin1",
]));
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

