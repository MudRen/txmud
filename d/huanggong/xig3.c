// Room: /d/huanggong/xig3.c

inherit ROOM;

void create()
{
	set("short", "ܽ����");
	set("long", @LONG
ܽ����������������԰��С���ϡ���������������Իʹ���
�߹���С��ˮ�峺���ף���ʱ�����Ծ��ˮ�棬ɷ�Ǻÿ���һ
֦��ˮ�ĺɻ���������������£��ԵĽ������Ρ��ŵľ�ͷ����
���������ԡ�ҡ�����ء�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xig6",
  "east" : __DIR__"xig4",
  "west" : __DIR__"xig1",
]));
	set("outdoors", "huanggong");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
