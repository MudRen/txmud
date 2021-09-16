// message.c

nomask varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;

	if(!me || !environment(me) )	return; // by Find.

	my_name= me->name();
	my_gender = me->query("gender");

	if(!my_name || !my_gender) return; // by Find.

	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( objectp(you) ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}

	message("vision", str1, me);
	message("vision", str3,  environment(me), ({ me, you}) );
}

nomask void tell_object(object ob, string str)
{
	message("tell_object", str, ob);
}

nomask varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

nomask void shout(string str)
{
	message("shout", str, users(), this_player());
}

nomask void write(string str)
{
	if(!str) return;  // by Find.
	if( this_player() )
		message("write", str, this_player());
	else if( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

nomask varargs void say(string str, mixed exclude)
{
	if( living(previous_object()) )
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}

// added for encode.
#ifdef GB_AND_BIG5
nomask int notify_fail(mixed arg)
{

    if (stringp(arg) && this_player())
        arg = (string)CONVERT_D->output(arg,this_player());

    return efun::notify_fail(arg);
}

nomask varargs void printf(mixed *arg1...)
{
	mixed *arg;
	string output;

	object ob = find_object(CONVERT_D);

	if(ob)
		arg1 = map_array(arg1,"output",ob);
	
	arg = arg1[1..];
	output = sprintf(arg1[0],arg...);
	write(output);
}
#endif
