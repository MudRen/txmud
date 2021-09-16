// nboard.c
// by Find.

#include <ansi.h>

#define BOARD_CAPACITY	500

inherit ITEM;
inherit F_SAVE;

class content
{
	string name;
	string id;
	string title;
	string msg;
	int time;
}

class content *notes = ({});

static string board_id;

void next_wizpost(string arg,object me,class content item);
void last_wizpost(string arg,object me,class content item);
void done_post(object me, class content item, string text);

void setup()
{
	set("no_get", 1);
        if(!clonep(this_object()))
                restore();
}

string query_save_file()
{
	string fname;

	if(!board_id)
	{
		fname = base_name(this_object());
		board_id = explode(fname,"/")[<1];
	}

	if( !stringp(board_id) )
		return 0;
	return sprintf(DATA_DIR"board/%s", board_id);
}

void init()
{
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
	add_action("do_wizpost", "wizpost");
}

int do_wizpost(string arg)
{
	class content item;
	object me = this_player();

	if(!wizardp(me) || wiz_level(me) < wiz_level("(admin)"))
		return 0;

	if(!arg)
		return notify_fail("留言请指定一个标题。\n");

	if(strlen(arg) > 18)
		return notify_fail("标题长度不要超过九个汉字。\n");

	item = new(class content);
	item->title = arg;
	item->time = time();

	write("请指定留言人姓名：");
	input_to( (: next_wizpost :), me,item);
	return 1;
}

void next_wizpost(string arg,object me,class content item)
{
	item->name = arg;
	write("请指定留言人的英文 ID：");
	input_to( (: last_wizpost :), me,item);
}

void last_wizpost(string arg,object me,class content item)
{
	item->id = arg;
	me->edit( (: done_post, me, item :) );
}

string short()
{
	int i, unread, last_read_time;

	if( !arrayp(notes) || !sizeof(notes) )
		return ::short() + " [ 没有任何留言 ]";

	if( this_player() )
	{
		last_read_time = (int)this_player()->query("board_last_read/" + board_id);
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]->time <= last_read_time ) break;
	}

	if( unread )
		return sprintf("%s [ 共有 %d 张留言，%s %d 张未读 %s ]", ::short(), sizeof(notes), HBMAG+HIR,unread,NOR);
	else
		return sprintf("%s [ 共有 %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
	int i, last_time_read;
	string msg;

	msg = query("long");
	if( msg[<1] != '\n' )
		msg += "\n";

	if( !pointerp(notes) || !sizeof(notes) )
		return msg + "\n留言版的使用方法请见 help board。\n" ;

	last_time_read = this_player()->query("board_last_read/" + board_id);
	for(i=0; i<sizeof(notes); i++)
		msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
			( notes[i]->time > last_time_read ? HIY: ""),
			i+1, notes[i]->title, notes[i]->name, ctime(notes[i]->time)[0..15] );

	return msg + "\n留言版的使用方法请见 help board。\n" ;
}

void done_post(object me, class content item, string text)
{
	item->msg = text;

	if(!notes || !sizeof(notes))
		notes = ({ item });
	else
	{
		if( sizeof(notes) > BOARD_CAPACITY )
			notes = notes[1..];
		notes += ({ item });
	}

	tell_object(me, "留言完毕。\n");

	save();
	return;
}

int do_post(string arg)
{
	class content item;
	object me = this_player();

        if(me->query("id") == "guest")
                return notify_fail("只有正式注册玩家才能使用留言板。\n");


	if(!arg)
		return notify_fail("留言请指定一个标题。\n");

	if(strlen(arg) > 18)
		return notify_fail("标题长度不要超过九个汉字。\n");

	item = new(class content);
	item->title = arg;
	item->name = me->query("name");
	item->id = me->query("id");
	item->time = time();

	this_player()->edit( (: done_post, this_player(), item :) );
	return 1;
}

int do_read(string arg)
{
	int num;
	mapping last_read_time;

	last_read_time = this_player()->query("board_last_read");

	if( !arrayp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

	if( !arg )
		return notify_fail("指令格式：read <留言编号>|new|next\n");

	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[board_id]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]->time > last_read_time[board_id] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	this_player()->start_more( sprintf(
"[%d] %-40s %s(%s)(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]->title, notes[num]->name,notes[num]->id, ctime(notes[num]->time)[0..9])
		+ notes[num]->msg );

	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ board_id: notes[num]->time ]) );
	else 
		if( undefinedp(last_read_time[board_id]) || notes[num]->time > last_read_time[board_id] )
			last_read_time[board_id] = notes[num]->time;

	return 1;
}


int do_discard(string arg)
{
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");

	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]->id != (string) this_player(1)->query("id")
	&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		return notify_fail("这个留言不是你写的，你无权删除。\n");

	if(sizeof(notes) == 1){
	    notes = ({});
	} else if(num == 0) {
	    notes = notes[num+1..<1];
	} else {
	    notes = notes[0..num-1] + notes[num+1..<1];
	}
	save();
	write("删除第 " + (num+1) + " 号留言....完成。\n");
	return 1;
}
