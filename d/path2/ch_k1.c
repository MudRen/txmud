// Room: /d/path2/ch_k1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ���ٵ������Ը��ⷱ����·�ϸ��ָ���������������
���ﲻ�����ǳ����֡���ʱ�������������߷ɳ۶���������һ
·������������Զ���ǳ����ǵ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ch_k2",
        "north" : "/d/changan/out_changan_s",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
