// Room: /d/tangmen/maowu.c

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ���ª��é���ݣ���������һ������������ֻ��һ��
ϯ�Ӻ�һ������ͷ�������һ����ľ�����ϰ��Ž����ָ�����ҩ
�ģ����ݳ���Ŵ̱ǵ�ҩζ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu2",
]));

	set("objects", ([
	__DIR__"npc/master_lai" : 1,
]));

	setup();
	replace_program(ROOM);
}
