// Room: /d/shaolin/qsl_room.c

inherit ROOM;

void create()
{
	set("short", "��ľ��");
	set("long", @LONG
������һƬŨ�ܵ�С��ľ�ԣ���������ԶԶ��ȥ��һ�����
������һ��ɽ�紵������ɳɳ���죬����һ����ɭ�ֲ��ĸо���
LONG
	);

	setup();
	replace_program(ROOM);
}
