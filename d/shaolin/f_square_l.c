// Room: /d/shaolin/f_square_l.c

inherit ROOM;

void create()
{
	set("short", "�㳡���");
	set("long", @LONG
�����������µĹ㳡��࣬���������׼ҵ����������ĵط���
�ϱ߰��Ÿ�һЩ�����õ���е����ʯ��ʲô�ĺ�һЩľ�ʱ�����
һЩ�׼ҵ��ӣ�������������š����������Ǵ����ã�������
ǰԺ�㳡�������ǹ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lroad1",
  "east" : __DIR__"f_square",
  "west" : __DIR__"zhongputang",
]));

	set("outdoors", "shaolin");
	set("objects", ([
	__DIR__"npc/jueyuan" : 1,
        __DIR__"npc/cleaner" : 1,
]));

	setup();
	replace_program(ROOM);
}
