// Room: /d/hangzhou/paths1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����վ�������ϰ���һ��С·�ϣ������￴��ȥ��������һ
���޼ʵĺɻ�����΢�紵�������ɻ�����չ�ģ�������С����
���д��У���ʱ������������������ֵĸ�����
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"stoneroad4",
  "east" : __DIR__"paths2",
]));

	setup();
	replace_program(ROOM);
}
