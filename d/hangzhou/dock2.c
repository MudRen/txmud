// Room: /d/hangzhou/dock2.c

inherit ROOM;

void create()
{
	set("short", "������ͷ");
	set("long", @LONG
����������������һ��С��ͷ������ˮǳ���󴬲����У���
���������һЩС�洬�����ؿ��˵������ĵĺɻ���һ�Σ�����
ȴ��ʵ����������Ҳ���Դ� (fill) Щ��ˮ���š�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"rockroad2",
]));

	set("resource/water",1);

	setup();
	replace_program(ROOM);
}
