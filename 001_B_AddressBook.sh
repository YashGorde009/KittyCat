createAddressBook() {
    if [ -e addressbook.txt ]; then
        echo "Address Book already created."
    else
        touch addressbook.txt
        echo "Address book created."
    fi
}

# Function to insert a record
insertARecord() {
    echo
    while true; do
        echo "To add a record to the address book, please enter the information in the format: \"last name, first name, email, phone number\" (no quotes or spaces)."
        echo "Example: Verma, Rajat, rajatverma@gmail.com, 1234567890"
        echo "To quit, press 'q'."
        
        read aInput
        if [ "$aInput" == "q" ]; then
            break
        fi

        echo "$aInput" >> addressbook.txt
        echo "The record has been inserted into the address book."
    done
}

# Function to view records
viewRecord() {
    while true; do
        echo "To display a record, enter the last name of the person (case sensitive)."
        echo "To quit, press 'q'."
        
        read dInput
        if [ "$dInput" == "q" ]; then
            break
        fi

        echo "Displaying records for \"$dInput\":"
        grep "$dInput" addressbook.txt
        RETURNSTATUS=$?
        
        if [ $RETURNSTATUS -eq 1 ]; then
            echo "No records found with the last name of \"$dInput\"."
        fi
    done
}

# Function to modify a record
modifyRecord() {
    echo
    while true; do
        echo "To modify a record, enter any search string, e.g., last name or email address (case sensitive)."
        echo "When finished editing the address book, enter 'q' to quit."
        
        read eInput
        if [ "$eInput" == "q" ]; then
            break
        fi
        
        echo "Listing records for \"$eInput\":"
        grep -n "$eInput" addressbook.txt
        RETURNSTATUS=$?

        if [ $RETURNSTATUS -eq 1 ]; then
            echo "No records found for \"$eInput\"."
        else
            echo "Enter the line number (the first number of the entry) that you'd like to edit."
            read lineNumber
            
            for line in $(grep -n "$eInput" addressbook.txt); do
                number=$(echo "$line" | cut -d':' -f1)
                if [ $number -eq $lineNumber ]; then
                    echo "What would you like to change it to? Use the format:"
                    echo "\"last name, first name, email, phone number\" (no quotes or spaces)."
                    read edit
                    sed -i "${lineNumber}s/.*/$edit/" addressbook.txt
                    echo "Address book updated."
                    break
                fi
            done
        fi
    done
}

# Function to delete a record
deleteRecord() {
    echo
    while true; do
        echo "To remove a record, enter any search string, e.g., last name or email address (case sensitive)."
        echo "If finished, enter 'q' to quit."
        
        read rInput
        if [ "$rInput" == "q" ]; then
            break
        fi
        
        echo "Listing records for \"$rInput\":"
        grep -n "$rInput" addressbook.txt
        RETURNSTATUS=$?

        if [ $RETURNSTATUS -eq 1 ]; then
            echo "No records found for \"$rInput\"."
        else
            echo "Enter the line number (the first number of the entry) of the record you want to remove."
            read lineNumber
            
            for line in $(grep -n "$rInput" addressbook.txt); do
                number=$(echo "$line" | cut -d':' -f1)
                if [ $number -eq $lineNumber ]; then
                    sed -i "${lineNumber}d" addressbook.txt
                    echo "The record was removed from the address book."
                    break
                fi
            done
        fi
    done
}

# Function to search for records
searchRecord() {
    echo
    while true; do
        echo "To search for a record, enter any search string, e.g., last name or email address (case sensitive)."
        echo "The format of a record is \"Last name, first name, email, phone number\"."
        echo "Example: Verma, Rajat, rajatverma@gmail.com, 1234567890"
        echo "To exit, enter 'q'."
        
        read sInput
        if [ "$sInput" == "q" ]; then
            break
        fi

        echo "Listing records for \"$sInput\":"
        grep "$sInput" addressbook.txt
        RETURNSTATUS=$?

        if [ $RETURNSTATUS -eq 1 ]; then
            echo "No records found for \"$sInput\"."
        fi
    done
}

# Main menu
if [ -n "$lastCharOfFile" ]; then
    echo >> addressbook.txt
fi

echo "Address Book"
echo "Enter your choice:"
echo "1 --> Create address book"
echo "2 --> Insert a record"
echo "3 --> View one or more records"
echo "4 --> Modify a record"
echo "5 --> Delete a single record"
echo "6 --> Search for records"
echo "7 --> Exit"

read input
case $input in
    1) createAddressBook;;
    2) insertARecord;;
    3) viewRecord;;
    4) modifyRecord;;
    5) deleteRecord;;
    6) searchRecord;;
    7) exit;;
    *) echo "Invalid option. Please try again.";;
esac
