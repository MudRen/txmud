// Room: /d/hangzhou/stree1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻ��ݳ����һƬ���֣�����С���ڲ�ͣ��ߴ�У��·���
����˵��ʲô�������յĵ��磬������ǳ����ĺõط���������
����Ļ��������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"spath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
