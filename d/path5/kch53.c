// Room: /d/path5/kch53.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
һ��Сͤ������һ�ߣ����������ͤ�ˡ���˵�Ǵ�ǰ���ɴ�
���߳��������ﷷ��ʱ�޽��ģ��Ӵ˺���������˾��еط���Ϣ
�ˡ�ͤ�ӱ��ϼ���һ������(pai)��
LONG
	);
	set("item_desc",([
          "����":"
	northwest    ���ɽ
	south        �ɶ�
\n",
	"pai":"
	northwest    ���ɽ
	south        �ɶ�
\n",
]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch54",
  "northwest" : __DIR__"kch52",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
