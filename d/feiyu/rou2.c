#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�Ų�������һ������С¥է���������������Ͼ���ϸ����
���񳯷�ͼ��һ�Ź��ӵ��ٰ��������У����ϵİ�����ɢ����
�����Ĺ����㣬ʫ�黭�⾡�����С�
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "enter" : "",
]));
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"rou3",
  "south" : __DIR__"rou1",
]));

	set(SAFE_ENV,1);
        setup();
}
