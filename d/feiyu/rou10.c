// Room: /wiz/louth/a/rou10.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ʰ�ĺܸɾ��ĵ�ʯ�ң�ʯ�ҵ�ǽ���ϵ��ż�����
�򣬵�������һЩ�ɲݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rou9",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/suibook" : 1,
]));
	setup();
	replace_program(ROOM);
}
