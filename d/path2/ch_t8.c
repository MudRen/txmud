
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/path2/ch_t8.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������������ˣ�������һƬ���֣��������е�С·һֱ
����ͨ���ƺӺ��ף�·���ϼ���һ�����ӡ�
LONG
	);
        set("item_desc",([
          "����":"
                  south    ��ͬ��\n",  
])); 
	set("exits", ([
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	"east" : "/d/phome/path2/bsjordan_home",
/*�����Զ��������.*/
 /* sizeof() == 3 */
  "northeast" : __DIR__"ch_t7",
  "south" : __DIR__"ch_t10",
  "west" : __DIR__"ch_t9",
]));
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 3,
]));

	set("outdoors", "path2");
	setup();
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,"/d/phome/path2/bsjordan_key");
/*�����Զ��������.*/

	replace_program(ROOM);
}
