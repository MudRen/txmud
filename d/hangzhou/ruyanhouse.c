// Room: /d/hangzhou/ruyanhouse.c

inherit ROOM;

void create()
{
	set("short", "���̼�");
	set("long", @LONG
�����Ǻ����������̵ļң����̱���ס����¥�У���Ϊ��
����֪�����˽��ã�֪�������ڳ���·���ð�������סլ������
��������ۡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changanw4",
]));

	setup();
	replace_program(ROOM);
}
