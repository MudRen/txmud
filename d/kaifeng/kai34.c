
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /u/w/wangs/b/kai34.c

inherit ROOM;

void create()
{
	set("short", "ɽ�Ͻ�");
	set("long", @LONG
��϶��ԣ�ɽ�Ͻֱȿ��⸮�������������խһ�㣬������
Ϊ��һ��ԭ����һƬƶ��ߣ�ֻ�ǵ�������꣬��������������
ʵ������Ÿĳɽֵ�������������Ѿ��Ҳ���һ�㵱��ƽ��ߵ�
Ӱ���ˣ���ʯ�̳ɵĴ����ֱ������Զ�������߶����۴��αȵ�
���̡�������һ�ҿ����̣�������������洫�˳�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"west" : "/d/phome/kaifeng/cindy_home",
/*�����Զ��������.*/
 /* sizeof() == 4 */
  "south" : __DIR__"kai37",
  "north" : __DIR__"kai2",
  "east" : __DIR__"kai36",
]));

	set("outdoors","kaifeng");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("west", "�������", "east", DOOR_CLOSED,LOCKED,"/d/phome/kaifeng/cindy_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
