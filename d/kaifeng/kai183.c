// Room: /u/w/wangs/b/kai183.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ�����ס������̨�Ϸ��Ŵ�С����ɹޣ���������
����֮��Ķ��������ȴ��Ӵ󿪣�Ʈ��һ�ɻ��ݵ�����ζ�����
��ʮ�����֣�һ�Ŵ�ľ���ӣ���Χ���ż������ӣ������������
һ�𣬲�֪��̸ʲô��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai160",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
