// Room: /wiz/louth/a/maowu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����é���ݣ�������ĳ���ǳ���ª���м�һ��
���ӣ��������Ӷ���һ����Ⱦ�����������������������������
��ס�����ӣ����Ĵ�ȴ����ɨ�ĸɸɾ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shan7",
]));
	setup();
	replace_program(ROOM);
}
