// Room: /d/fengtian/shenwu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ϊ������������Ե�����Ӣ�ۡ�����󽫾������֮
�����������������һֱ��������λ�������ص�Ӣ�ۣ���������
�����ĺ��������������פ�أ�һֱ�Ƕ���˹�˰����ɻ��һ֧
��װ������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xh2",
]));

	setup();
	replace_program(ROOM);
}
