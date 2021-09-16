// Room: /d/hangzhou/linneiyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������ָ�����Ժ��������һ����ӣ��������ּҵĿ���
���ſ����������˺ϱ�����ͩ������������ʿһ�����������
��������һ��ƽ�������Ҷ��Ǿ�ס��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"linguard",
  "west" : __DIR__"linyuanzi",
  "east" : __DIR__"linketing",
  "north" : __DIR__"linpath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
