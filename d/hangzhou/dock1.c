// Room: /d/hangzhou/dock1.c

inherit ROOM;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
����������������һ��С��ͷ������ˮǳ���󴬲����У���
���������һЩС�洬�����ؿ��˵������ĵĺɻ���һ�Σ�����
ȴ��ʵ����
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"stoneroad3",
]));

	setup();
	replace_program(ROOM);
}
