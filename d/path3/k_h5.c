// Room: /d/path3/k_h5.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
�����Ǹ�����·�ڣ�λ�ڿ��⸮������ʮ����ĵط���Ҳ��
����ԭ������һ��Ҫ�������Ϸ�����һƬ���֣�����¶��һ��С
·��������һ��·�������ˣ�����������Щʱ�����ͨ�С�·��
����һ������(pai)��
LONG
	);
        set("item_desc",([
          "pai":"
	east         ������
	west         ���⸮
	southeast    ͭ��
\n",
          "����":"
	east         ������
	west         ���⸮
	southeast    ͭ��
\n",
]));

	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h6",
  "west" : __DIR__"k_h4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
