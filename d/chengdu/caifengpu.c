// Room: /wiz/louth/c/caifengpu.c

inherit ROOM;

void create()
{
	set("short", "�÷���");
	set("long", @LONG
����������ǳ�ׯ�����ĳɶ��÷��̡�����÷��̵���ɫ��
�����������ͷ�����ʮɫ����Ϊ�ḻ���γɶ�ׯ�����á����š�
���޵Ķ����������ÿ�궼�������ղؼ����������ϼ�����
ͷ�ؼ���ء��������ȥ���Ǹ����֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fdjie5",
]));

	setup();
	replace_program(ROOM);
}
