// Room: /d/hangzhou/paths2.c

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

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"paths1",
]));

	set("objects",([
	__DIR__"npc/shusheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
