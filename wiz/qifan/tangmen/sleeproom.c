// Room: /d/tangmen/sleeproom.c

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
����һ����ķ��䣬�������Է��������񴲣��Ĵ���ɨ��
һ����Ⱦ��������ǵ�������Ϣ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ssl2",
]));

	set(SAFE_ENV, 1);
	set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
