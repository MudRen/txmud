// Room: /d/hangzhou/zfchaifang.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
������һ��񷿣�ǽ�Ƕ��ų�ɽ�Ĳ�ݣ��Ա�����һЩũ��
����ǽ��С������һ��é���̳ɵĵ��̣��Ա߰���һ���ִŴ���
�������ǳ����õġ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zfpath4",
]));

	setup();
	replace_program(ROOM);
}
