// Room: /d/hangzhou/zfwife.c

inherit ROOM;

void create()
{
	set("short", "�����Է�");
	set("long", @LONG
���Ǻ���֪������Ԫ������˵��Է�������˱�����ʡѲ��
����˵�ǧ�𣬸���֮���Գ�Ϊ����֪��Ҳȫ�ǿ��������˵İ�
����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath8",
]));

	setup();
	replace_program(ROOM);
}
