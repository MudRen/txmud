// Room: /u/w/wangs/b/kai181.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ�����ס������̨�Ϸ��Ŵ�С����ɹޣ���������
����֮��Ķ��������ȴ��Ӵ󿪣�Ʈ��һ�ɻ��ݵ�����ζ�����
��ʮ�����֣�һ�Ŵ�ľ���ӣ���Χ���ż������ӣ�һλ�ϴ�����
����������,��֪��߶��ʲô.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai157",
]));
        set("objects",([
        __DIR__"npc/laoniang": 1,
]));

	setup();
	replace_program(ROOM);
}
