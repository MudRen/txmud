// Room: /d/hangzhou/zhifu.c

inherit ROOM;

void create()
{
	set("short", "֪������");
	set("long", @LONG
����ǰ�Ǻ��ݸ���֪�����ţ���Ȼ���ɷǷ��������������
�����˻�ͭ�Ŷ��������������һ����ɫ���ң����顰���ݸ���
������ɫ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guotaiw2",
  "north" : __DIR__"zfyuanzi",
]));

	setup();
	replace_program(ROOM);
}
