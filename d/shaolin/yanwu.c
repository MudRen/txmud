// Room: /d/shaolin/yanwu.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����ÿ���������ִ����޺���ĵط���
�������䳡��������Ҳ���е���ġ����䳡�����ܹ���д�С���
�֡����ֵ��ӻ��죬�㳡�м�����Ͼ�Ȼ�ĺܶ�����Ľ�ӡ����
�������󷨵��Ͻ����������򶫺��������ǹ��������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tianwang",
  "east" : __DIR__"rroad5",
  "west" : __DIR__"lroad5",
]));
        set("objects", ([
        __DIR__"npc/cleaner" : 1,
]));


	setup();
	replace_program(ROOM);
}
