// Room: /d/huanggong/xig1.c

inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
�������������԰����԰��������������Ļ��䣬�������
�������ｨ�����Լ��ļҡ��������ǿ����ļ��ڣ�����۷䶼��
ææµµ�Ĳɼ����ۡ�ÿ��΢�紵���������˵Ļ������������
�����㲻������һ�ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xigdm",
  "east" : __DIR__"xig3",
  "west" : __DIR__"xig2",
]));
	set("outdoors", "huanggong");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}