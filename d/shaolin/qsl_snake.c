// Room: /d/shaolin/qsl_snake.c

inherit ROOM;

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
������һƬŨ�ܵ�С��ľ�ԣ���������ԶԶ��ȥ��һ�����
������һ��ɽ�紵������ɳɳ���죬����һ����ɭ�ֲ��ĸо���
LONG
	);

	set("objects",([
	__DIR__"npc/snake" : 1,
]));

	setup();
}

void check_set_up()
{
	if(find_call_out("reset") == -1)
		call_out("reset", 60);
}
