// Room: /d/path5/kch29.c

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
����һ�����յ���ϸɽʯ��������һ�������ô������ߵ���
��֮�ϡ������紵��ɹ���ܣ����泤���˰��̵�̦޺������û��
��������˺���ͨ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kch28",
  "east" : __DIR__"kch30",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
