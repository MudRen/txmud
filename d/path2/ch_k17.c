// Room: /d/path2/ch_k17.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
����һ�������̳ɵĸ�ԭ������������·���Եĸ���ɳɳ
���졣̧�ۿ�ȥ��һ���޼ʵĻ�����ԭ�����������������Ǹ�
��������㲻���ٸ������泩��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k16",
  "south" : __DIR__"ch_k18",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
