// songshulin.c
// by dicky 2002-12-9

inherit ROOM;

void create()
{
	set("short", "ɽ������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص�������
����ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β�������
LONG);


	set("outdoors", "taxue");

	set("exits", ([
		"east" : __DIR__"milin2",
		"south" : __DIR__"undertree",
	]));

	setup();
	replace_program(ROOM);
}



