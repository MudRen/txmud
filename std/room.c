// room.c
// by Find.

#pragma save_binary

#undef DEBUG

#include <ansi.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;
inherit F_NATURE;

static mapping doors;
static int origin_clean_up;

void do_close_gate();
nomask mapping check_object(string file,mapping ob);
int query_max_encumbrance() { return 100000000000; }
int query_max_items() {return 30;}
int is_room() {return 1;}

mixed set(string prop, mixed data)
{
	if( (prop == "short") && stringp(data) )
		data =  HIY "��"+data+ HIY "��" NOR;

	return ::set(prop, data);
}

nomask object make_inventory(string file)
{
	object ob;

	ob = new(file);
	if(!ob)
		return 0;

	if(ob->is_ctl_ob()	// control ob.
	&& !ob->is_character()
	&& !ob->valid_clone())
	{
		destruct(ob);
		return 0;
	}

	if(ob->is_time_ctl_ob() && !ob->query_is_valid_time())
	{
		call_out("reset",ob->query_lasting_time());
		destruct(ob);
		return 0;
	}

	ob->move(this_object());
	ob->set("startroom", base_name(this_object()));

// added by Find.
#ifdef WIZARD_FLAG
	if(query_wiz_flag())
		ob->set_flag(1);
#endif
// end.

	return ob;
}

void reset()
{
	mapping ob_list, ob;
	string *list;
	int i,j,n,flag;
	object *inv;

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is 
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//

// added by find.
	if(query("GATE_ROOM"))
	{
		string day_night;
		int time;

		if(sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time))
		{
			if(day_night == "day")
			{
				if(find_call_out("close_gate") == -1)
					call_out("close_gate",time);
			}
			if(day_night == "night")
			{
				do_close_gate();
				if(find_call_out("open_gate") == -1)
					call_out("open_gate",time);
			}
		}
	}
// end.

	if(!clonep(this_object()) && (n = sizeof(inv = all_inventory(this_object()))))
	{
		foreach(object tmp in inv)
			if(objectp(tmp)
			&& (tmp->is_weapon()
                        || tmp->is_armor())
			&& (tmp->query("startroom") != base_name(this_object())) )
				destruct(tmp);
	}

	// �˴������˸���,�� make_inventory() ֮ǰ���м��.
	// ����Ϸ�д����ɴ˷����������ͬһ���,�Ͳ����ٸ���.
	// ���� reset ���� load_object ��Ҫ���д˼��.
	// ���緿������������ bigbug,��������һ��,update �˷���
	// ��ֻ�������bigbug,��ȫ������,update һ��Ҳ�����.
	// ��Ȼ��ʱ����� return_home() ����,�����'��'��,�⻹
	// �ǻ�������,����������return_home������,���Ǳ����Ƴ�
	// ����,�����������Ȼ�Ͳ�����.
	// �˴�ʩ������Ϸ����Դ�����޷���,��������Ϸ����߾���
	// ��Ƶ���Ϸƽ����ȫ����.���ɱ��������ʦ update ����
	// ���ิ������ĳ������.
	// �� define WIZARD_FLAG ����Ч.
	// by Find.

	ob_list = query("objects");
	if( !mapp(ob_list) ) return;
	
	if( !mapp(ob = query_temp("objects")) )
		ob = allocate_mapping(sizeof(ob_list));
	list = keys(ob_list);
	for(i=0; i<sizeof(list); i++)
	{
		// Allocate an array if we have multiple same object specified.
		if( undefinedp(ob[list[i]])
		&& intp(ob_list[list[i]])
		&& ob_list[list[i]] > 1 )
			ob[list[i]] = allocate(ob_list[list[i]]);

#ifdef WIZARD_FLAG	// Find.
		if(find_object(list[i]))
			ob = check_object(list[i],ob);
#endif

		switch(ob_list[list[i]])
		{
		case 1:
			if( !ob[list[i]] )
				ob[list[i]] = make_inventory(list[i]);
			if( ob[list[i]]		// control ob.
			&& environment(ob[list[i]]) != this_object()
			&& ob[list[i]]->is_character() )
			{
				if( !ob[list[i]]->return_home(this_object()) )
				{
					if(!origin_clean_up)
						set("no_clean_up", 1);
					flag++;
				}
			}
			break;
		default:
			for(j=0; j<ob_list[list[i]]; j++)
			{
				// If the object is gone, make another one.
				if( !objectp(ob[list[i]][j]) )
				{
					ob[list[i]][j] = make_inventory(list[i]);
					continue;
				}
				// Try to call the wandering npc come back here.
				if( environment(ob[list[i]][j]) != this_object()
				&& ob[list[i]][j]->is_character() )
				{
					if( !ob[list[i]][j]->return_home(this_object()) )
					{
						if(!origin_clean_up)
							set("no_clean_up", 1);
						flag++;
					}
				}
			}
		}
	}

	if(!flag && query("no_clean_up") && !origin_clean_up)
		delete("no_clean_up");

	set_temp("objects", ob);
}

nomask mapping check_object(string file,mapping ob) /* by Find. */
{
	object *objs;
	int n,i;

	objs = children(file);
	for(n=0;n<sizeof(objs);n++)
	{
		if(clonep(objs[n]) && objs[n]->query("startroom") == base_name(this_object()))
		{
			if( arrayp(ob[file]) )
			{
				if(member_array(objs[n],ob[file]) == -1)
				{
					for(i=0;i<sizeof(ob[file]);i++)
					{
						if(!objectp(ob[file][i]))
						{
						ob[file][i] = objs[n];
						i=sizeof(ob[file]);
						}
					}
				}
			}
			else
				ob[file] = objs[n];
		}
	}
	return ob;
}

// Ϊlock��������������
int lock_door(object me,string dir, int from_other_side)
{
	mapping exits;
	object ob,*inv;
	int i;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("�������û���š�\n");

	if( !(doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "�ǿ��ŵ���ô����ѽ��\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door without an exit.\n");
	if( undefinedp(doors[dir]["lock_state"]) )
		return notify_fail(doors[dir]["name"]+"��û������\n");
	if( doors[dir]["lock_state"] == LOCKED )
		return notify_fail(doors[dir]["name"]+"�Ѿ��������ˡ�\n");

	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{
		if(base_name(inv[i]) == doors[dir]["key_file"])
			break;
	}
	if (i >= sizeof(inv))
		return notify_fail("������û��"+
		doors[dir]["name"]+"��Կ�ף�û�����������š�\n");

	if( from_other_side )
		message("vision", "ֻ����" + doors[dir]["name"] +
		"����ડ�һ�������������������˴���һ�������ˡ�\n", this_object());
	else
	{
		if(!ob = find_object(exits[dir]))
			ob = load_object(exits[dir]);
		if( objectp(ob) )
			if( !ob->lock_door(me,doors[dir]["other_side_dir"], 1) )
				return 0;
	}

	doors[dir]["lock_state"] = LOCKED;
	return 1;
}

int unlock_door(object me,string dir, int from_other_side)
{
	mapping exits;
	object ob,*inv;
	int i;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("�������û���š�\n");

	if( !(doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ������ˡ�\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door without an exit.\n");
	if( undefinedp(doors[dir]["lock_state"]) )
		return notify_fail(doors[dir]["name"]+"��û������\n");
	if( doors[dir]["lock_state"] == UNLOCKED )
		return notify_fail(doors[dir]["name"]+"�ϵ����Ѿ������ˡ�\n");

	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{
		if(base_name(inv[i]) == doors[dir]["key_file"])
			break;
	}
	if (i >= sizeof(inv))
		return notify_fail("������û��"+
		doors[dir]["name"]+"��Կ�ף�û�������������\n");
	
	if( from_other_side )
		message("vision", "ֻ����" + doors[dir]["name"] +
		"����ડ�һ�������������������˴���һ����ˡ�\n", this_object());
	else
	{
		if(!ob = find_object(exits[dir]))
			ob = load_object(exits[dir]);
		if( objectp(ob) )
			if( !ob->unlock_door(me,doors[dir]["other_side_dir"], 1) )
				return 0;
	}

	doors[dir]["lock_state"] = UNLOCKED;
	return 1;
}
// end.

// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
	string master;
	object ob;
	mapping exits = query("exits");

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "��Ҫ��ʲ�᣿\n";

	// modified by Find.
	if(!ob = find_object(exits[dir]))
		ob = load_object(exits[dir]);
	if( objectp(ob) && ob->is_player_home())
		master = ob->home_master();

	if( doors[dir]["status"] & DOOR_CLOSED )
	{
		return "���" + doors[dir]["name"] + "�ǹ��ŵ�"+
		((doors[dir]["lock_state"] == LOCKED)?((!master)?"":"��"+"������"+master+"�ļ�")+
		"�����Ϲ���һ������"
		:((!master)?"��":"��"+"������"+master+"�ļҡ�"))+"\n";
	}
	else
		return "���" + doors[dir]["name"] + "�ǿ��ŵ�"+
		((!master)?"��":"��"+"������"+master+"�ļҡ�")+"\n";
}

varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("�������û���š�\n");

	if( !(doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ��ŵ��ˡ�\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door without an exit.\n");

	if(doors[dir]["lock_state"] == LOCKED)	// �ȿ������š�
		return notify_fail(doors[dir]["name"]+"�����ŵġ�\n");
	if( from_other_side )
		message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "���ˡ�\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] &= (!DOOR_CLOSED);
	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("�������û���š�\n");

	if( (doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "�Ѿ��ǹ��ŵ��ˡ�\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: close_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "�����ˡ�\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] |= DOOR_CLOSED;
	return 1;
}

int check_door(string dir, mapping door)
{
	// If we have no responding door, assume it is correct.
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return 0;

	door["status"] = doors[dir]["status"];
	door["lock_state"] = doors[dir]["lock_state"];
	return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir,
int status,string lock_state,string key_file)
{
	mapping d, exits;
	object ob;
	int lock_flag;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: create_door: attempt to create a door without exit.\n");

	if(!lock_state)
		lock_flag = 0;	// û����.
	else if(!stringp(lock_state) || !stringp(key_file) || key_file == "")
		error("Room: lock state and key file must string.\n");
	else if(file_size(key_file+".c") <= 0)
		error("Room: can not find key object.\n");
	else if( (lock_state != LOCKED) &&(lock_state != UNLOCKED) )
		error("Room: lock state error! must one of \"lock\" or \"unlock\".\n");
	lock_flag = 1;	// ����.
	// Compact mode.
	if( stringp(data) )
	{
		d = allocate_mapping((lock_flag)?6:4);
		d["name"] = data;
		d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
		d["status"] = status;
		if(lock_flag)
		{
			d["lock_state"] = lock_state;
			d["key_file"] = key_file;
		}
	} else if( mapp(data) )
		d = data;
	else
		error("Create_door: Invalid door data, string or mapping expected.\n");

	set("item_desc/" + dir, (: look_door, dir :) );

	if( objectp(ob = find_object(exits[dir])) )
		ob->check_door(other_side_dir, d);

	if( !mapp(doors) ) doors = ([ dir: d ]);
	else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
	else return doors[dir][prop];
}

/*
 * ����һ�������ĺ�������������������á�
 * �� summon ���ܷɵ��书����ʹ���뿪ԭ��
 * ��� action �ȡ�
 * ��Ȼ����Щ���û��Ҫһ���������������
 * ���������ҪΪ��һ���������߶�������ס
 * һ����������г��ڶ���ġ�
 * ���ɹ��� move action Ϊ�Ͻ��������Ӧ��
 * ����һ��������������������ȥ�Ļ��ǿ���
 * ��ס���г��ڣ����Ͳ�֪��˭����ô�ۡ�
 * move action ͬ��
 * by Find.
 */
void refresh_guarding(object me)
{
	mapping guards;
	string *dirs;
	int i;
	mixed guarding;
	object *guarded;

	guards = query("guarded");
	if(mapp(guards) && guards != ([]))
	{
		dirs = keys(guards);
		for(i=0;i<sizeof(dirs);i++)
		{
			if( !arrayp(guards[dirs[i]]) || guards[dirs[i]] == ({}) )
				continue;
			guards[dirs[i]] -= ({0});
			if(member_array(me,guards[dirs[i]]) != -1)
				guards[dirs[i]] -= ({me});
		}
		set("guarded",guards);
	}
	/* me �� guarding Ҳ����ˢ�ɣ����ڱ�ĵط����������ࡣ*/
	guarding = me->query_temp("guarding");
	if(objectp(guarding))
	{
		if(arrayp(guarded = guarding->query_temp("guarded"))
		&& member_array(me,guarded) != -1)
		{
			guarded -= ({me});
			if( living(guarding) )
                        	tell_object(guarding, me->name() + "���ٱ������ˡ�\n");
			guarding->set_temp("guarded",guarded);
		}
	}
	me->delete_temp("guarding");
	return;
}

int valid_leave(object me, string dir)
{
        mapping block;
        object *body;
        int i;

	if(!me || !dir)
		return 1;

	if( mapp(doors) && !undefinedp(doors[dir]) )
	{
		if( doors[dir]["status"] & DOOR_CLOSED )
			return notify_fail("������Ȱ�" + doors[dir]["name"] + "�򿪣�\n");
		// if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
	}
        block = query("guarded");
        if( !mapp(block) || undefinedp(block[dir]))
	{
		refresh_guarding(me);// by Find.
		return 1;
	}
        body = block[dir];

	if( arrayp(body) )
	{
		for(i=0;i<sizeof(body);i++)
		{
			if( body[i]
			&& living(body[i])
			&& !body[i]->query_temp("netdead")  /* by Find. ��������Ч��*/
			&& (this_object() == environment(body[i]))
			&& (body[i]->query("kee") > (body[i]->query("max_kee")/10)))
			/* ������С�� 10% ���Ǳ����������˵�ȥ·�ˡ�*/
			{
				if(me==body[i]) continue; 
				if(( ( (random(me->query_skill("move"))+me->query_skill("move"))/2
				<body[i]->query_skill("move") )
				|| ( (random(me->query_skill("dodge"))+me->query_skill("dodge"))/2
                                     <body[i]->query_skill("dodge") ) ) )
				{
					if( userp(me) && (me->query("age") <= PROTECT_AGE) )
						tell_object(body[i],
						sprintf("�㷢����һ��С�������˹��������ǲ����ÿ���%s���ȥ·��\n",
						to_chinese(dir)));
					else
					{
					tell_object(body[i],sprintf("��һ������ס��%s��%s���ȥ·��\n",
						me->name(),to_chinese(dir)));
					body[i]->receive_damage("kee",10+random(6),"tire");
					// ÿ�ε�ס���˵�ȥ·��Ҫ����һ����������
					// ��˴����Ų������˸����޼ɵ��� guard �ˣ�
					// Ҳ�ȽϽӽ���ʵ��by Find.
					return notify_fail("�������"+body[i]->query("name")+ "��ס��!\n");
					}
				}
			}
		}  
	}
	refresh_guarding(me); // by Find.
	return 1;
}

void setup()
{
	seteuid(getuid());

#ifdef DEBUG //by Find.
	if(previous_object())
		log_file("room_log","pre0: "+file_name(previous_object())+"\n");
	if(previous_object(1))
		log_file("room_log","pre1: "+file_name(previous_object(1))+"\n");
#endif

	if(query("no_clean_up"))
		origin_clean_up = 1;

	// by Find.
	if(previous_object() && previous_object() == find_object(CLONE_CMD))
	{
		//error("Room: error to clone a ROOM file.\n");
		destruct(this_object());
		return;
	}

// added by find.
#ifdef WIZARD_FLAG
	if( !sscanf(base_name(this_object()), "/d/%*s")
	&& !virtualp(this_object()) && !clonep(this_object()) )
		set_flag(1);
#endif
// end.

	this_object()->reset();
}

// added by Find. For gate room.
void open_gate()
{
	string open_look,gate_name;
	mapping gate_dir,exits;
	string *dir;
	string day_night;
	int time;

	remove_call_out("open_gate");
	gate_dir = query("gate_dir");
	open_look = query("open_look");
	gate_name = query("gate_name");

	if(!mapp(gate_dir) || !stringp(open_look) || !stringp(gate_name))
		return;

	dir = keys(gate_dir);
	if(sizeof(dir) > 1)
		return;
	if(!query("exits/"+dir[0]))
	{
	set("long",open_look);
	if( !mapp(exits = query("exits")) )
		set("exits/",gate_dir);
	else
		{
		exits += gate_dir;
		set("exits",exits);
		}
	tell_object(this_object(),BCYN HIY "���ն�����"+gate_name+"���ˡ�\n" NOR);
	}

	// ÿ����ҹ���涼�� mud_time ��һ��ʱ�����ֿ�����ʱ�侫ȷ��
	// ͬʱҲ��֤�����߷��俪���ŵ�ͬ����
	if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
	{
		if(day_night == "day")
			call_out("close_gate",time);
		else if(day_night == "night")
			call_out("close_gate",time+840);
	}
}

void close_gate()
{
	string day_night;
	int time;

	remove_call_out("close_gate");
	do_close_gate();
	tell_object(this_object(),BBLU HIC "��ɫ����"+query("gate_name")+"�����ˡ�\n" NOR);

	// ÿ����ҹ���涼�� mud_time ��һ��ʱ�����ֿ�����ʱ�侫ȷ��
	// ͬʱҲ��֤�����߷��俪���ŵ�ͬ����
	if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
	{
		if(day_night == "day")
			call_out("open_gate",time+600);
		else if(day_night == "night")
			call_out("open_gate",time);
	}
}

void do_close_gate()
{
	string close_look,open_look,gate_name;
	mapping gate_dir;
	string *dir;

	gate_dir = query("gate_dir");
	close_look = query("close_look");
	gate_name = query("gate_name");

	if(!mapp(gate_dir) || !stringp(close_look) || !stringp(gate_name))
		return;
	dir = keys(gate_dir);
	if(sizeof(dir) > 1)
		return;

	if(query("exits/"+dir[0]))
	{
	open_look = query("long");
	set("long",close_look);
	delete("exits/"+dir[0]);
	set("open_look",open_look);
	}
}

void load_board(string board)
{
	string file;
	object ob;

	if(!board)
		return;

	if(board[0] == '/')
		file = board;
	else
		file = sprintf("/obj/board/%s",board);

	if(file_size( file + ".c") <= 0)
		return;

	if( !objectp(ob = find_object(file)) && !objectp(ob = load_object(file)) )
		return;

	ob->move(this_object());
}

void set_check_dtime(int t)
{
	if(!intp(t) || (t <= 0))
		return;

	call_out("reset", t);
}
