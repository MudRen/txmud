// Room: /d/hangzhou/butcherroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��СС�����̣������ϰ���һ������ʵ����⣬���
������ƹ��������������ص��ǵ�վ�ڰ��󣬸���ߺ���ţ�
�������˿������������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yongningn1",
]));

	setup();
	replace_program(ROOM);
}
