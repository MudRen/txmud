// Room: /wiz/louth/a/slroom.c

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������
�������ֻ���м����һ����ʰ����������Ĵ󴲣�����
��������˯����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yu45",
]));
        set("sleep_room", 1);
        set(SAFE_ENV,1);

	setup();
	replace_program(ROOM);
}
